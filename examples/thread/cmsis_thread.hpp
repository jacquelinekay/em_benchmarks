#ifndef CMSIS_THREAD_HPP_
#define CMSIS_THREAD_HPP_

#include <atomic>
#include <cmsis_os.h>

#define CMSIS_THREAD_JOINED_SIGNAL 0x6A
// The number of threads that can wait on another thread to join
#define CMSIS_THREAD_MAX_JOIN_THREADS 16

namespace cmsis_cpp {

void cmsis_thread_handle_error() { std::terminate(); }

template <typename F, template<typename> typename Allocator>
struct CMSISThread {
public:
  CMSISThread(F &&f) : raw_function(f), finished(false) {
    auto wrapped_function = +[](void const *args) -> void {
      auto thread_argument = static_cast<const CMSISThread *>(args);
      if (!thread_argument) {
        cmsis_thread_handle_error();
      }
      thread_argument->raw_function();
      for (const auto &tid : thread_argument->waiting_tids) {
        osSignalSet(tid, CMSIS_THREAD_JOINED_SIGNAL);
      }
    };
    osThreadDef(wrapped_function, osPriorityAboveNormal, 1, 0);
    tid = osThreadCreate(osThread(wrapped_function), this);
  }

  void terminate() {
    if (finished) {
      return;
    }
    osThreadTerminate(tid);
    finished = true;
  }

  void join() {
    if (finished) {
      return;
    }
    waiting_tids.push_back(osThreadGetId());
    osEvent event = osSignalWait(CMSIS_THREAD_JOINED_SIGNAL, osWaitForever);
    switch (event.status) {
      case osEventSignal:
        return;
      /* ...Handle other known signals... */
      default:
        cmsis_thread_handle_error();
    }
  }

  ~CMSISThread() {
    terminate();
  }

private:
  osThreadId tid;
  F raw_function;
  std::atomic<bool> finished;
  std::vector<osThreadId, Allocator<osThreadId>> waiting_tids;
};

} // namespace cmsis_cpp

#endif  // CMSIS_THREAD_HPP_

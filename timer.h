/* Header File for Timer system */

#if     !defined(__TIMER_H)
#define __TIMER_H

#ifdef IMPLEMENT_ME

#define InitialiseTimer() sosTIMERInitSystem(_TIMER_DOS_RATE,_SOS_DEBUG_NORMAL)
#define UnInitialiseTimer() sosTIMERUnInitSystem(0)
#define AddTimer(rate,handler,handle) sosTIMERRegisterEvent(rate,handler,&handle)
#define RemoveTimer(handle) sosTIMERRemoveEvent(handle)

#else

#define InitialiseTimer()
#define UnInitialiseTimer()
#define AddTimer(rate,handler,handle)
#define RemoveTimer(handle)

#endif

#endif  /* __TIMER_H */

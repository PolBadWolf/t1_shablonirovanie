
#include "main.h"
#include "UserTimer.h"

#ifdef DISPLAY_TIMER
void UserTimerDisplay(void)
{
}
#endif

#ifdef USERTIMERUSER
//bool fl = true;
//int sch;
void UserTimerUser(void)
{
  //PowerDown::timer();
  //og::timer();
  speedmetr::Timer();
}
#endif




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
unsigned int t_count = 0;
void UserTimerUser(void)
{
  //PowerDown::timer();
  og::timer();
  t_count++;
  if (t_count>=1000) t_count = 0;
}
#endif



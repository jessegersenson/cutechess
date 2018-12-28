#include "speedupromps.h"
#include <QtGlobal>

SpeedupRomps::SpeedupRomps(int baseTimeLeft,
						   int timeIncrement,
						   int scoreLimit,
						   int gamePlyLimit,
						   int seqPlyLimit)
	: m_baseTimeLeft(baseTimeLeft)
	, m_increment(timeIncrement)
	, m_scoreLimit(scoreLimit)
	, m_gamePlyLimit(gamePlyLimit)
	, m_murderPlyLimit(seqPlyLimit)
{}


void SpeedupRomps::update(int cur_ply, int cur_score, int prev_score)
{
   if (m_state != Monitoring)
       return;

   bool oneSideMurders = cur_ply > m_gamePlyLimit
       && qAbs(cur_score) >= m_scoreLimit
       && qAbs(prev_score) >= m_scoreLimit;

   if (oneSideMurders)
   {
       if (m_murderPlyCount < m_murderPlyLimit)
           m_murderPlyCount++;

       if (m_murderPlyCount >= m_murderPlyLimit)
           m_state = ReadyForResets;
   }
   else
       m_murderPlyCount = 0;
}

bool SpeedupRomps::isResetNeeded() const
{
   return m_state == ReadyForResets || m_state == OneIsReseted;
}

void SpeedupRomps::incResetCount()
{
   Q_ASSERT(m_state != Monitoring);
   Q_ASSERT(m_state != Finished);
   m_state = m_state == ReadyForResets ? OneIsReseted : Finished;
}

int SpeedupRomps::newTimeLeft() const
{
   return m_baseTimeLeft + m_increment;
}

int SpeedupRomps::newTimeInc() const
{
   return m_increment;
}

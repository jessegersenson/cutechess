#ifndef SPEEDUPROMPS_H
#define SPEEDUPROMPS_H

/*!
 * \brief Time resets for winning positions
 *
 * The purpose is to speedup game endings when the position is "clearly
 * winning". In order to end a game quickly the time control can be changed if
 * the score is above X cp for Y moves, and the game has reached a minimum
 * number of moves Z.
 */
class LIB_EXPORT SpeedupRomps
{
public:

	/*! Initialization */
	SpeedupRomps(int baseTimeLeft,
				 int timeIncrement,
				 int scoreLimit,
				 int gamePlyLimit,
				 int seqPlyLimit);

   /*! Updates the state on each ply */
   void update(int cur_ply, int cur_score, int prev_score);

   /*! Returns true if time reset is needed */
   bool isResetNeeded() const;

   /*! Increments number of resets */
   void incResetCount();

   /*! How much time is left after reset (in milliseconds) */
   int newTimeLeft() const;

   /*! New time increment after reset (in milliseconds) */
   int newTimeInc() const;

private:
   /*! The status of the romps. */
   enum State {
       Monitoring = 0,
       ReadyForResets,
       OneIsReseted,
       Finished
   };

   int m_baseTimeLeft;
   int m_increment;
   int m_scoreLimit;
   int m_gamePlyLimit;
   int m_murderPlyLimit;
   State m_state;
   int m_murderPlyCount;
};

#endif // SPEEDUPROMPS_H

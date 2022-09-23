#ifndef _VENEZIA_SYSTEM_H
#define _VENEZIA_SYSTEM_H

/**
 * Get system timer value
 *
 *
 */
unsigned long long vnzSystemGetTimeWide();

/**
 * Get low part of system timer value
 *
 *
 */
unsigned int vnzSystemGetTimeLow();

/**
 * Delay with busy wait
 *
 *
 */
void vnzSystemDelay(unsigned long long usec);

/**
 * Get core number that executes current V-Thread
 *
 *
 * @return core number
 */
int vnzSystemGetCoreNum();

#endif /* _VENEZIA_SYSTEM_H */

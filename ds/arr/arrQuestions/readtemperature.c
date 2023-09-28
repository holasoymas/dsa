// HACK:Read the group of temeprature readings, A latitude at which the reading
// was taken , an integer between -90 and 90 , representing the latitude at
// which the reading was taken, and the observed themprature at that latitude.
// Print a table consisiting of each latitude and the average temerature at that
// latitude. If there are no readings at  particular latitude , print "NODATA "
// instead of spare(the nothern consists of latitude 1 to 90 and hte southern
// consists of -1 through -90) This average temeprature should be computed as
// the average of the averages not the average of the original readings. Also
// determine preatures in all latitude of each hemisphere for which there are
// data for both that there is data for latitude 57 but not for latitude -57,
// then the average temperature for latitude 57 should be ignored in determing
// which hemisphere is warmer ?
//

#include <stdio.h>

int main(void) {
  int northernLat, southernLat, noOfNorthernLat, noOfSouthernLat;

  int sumOfNorthTmp = 0, avgTmpOfNorthLat;
  printf("Enter the value of Northern Latitude (0 - 90)\n");
  scanf("%d", &northernLat);
  printf("How many temperature do you have for northern lat ?");
  scanf("%d", &noOfNorthernLat);
  if (noOfNorthernLat == 0) {
    printf("NO DATA FOR NORTHERN HEMISPHERE AT ALT %d\n", northernLat);
  } else {
    int northTmpArr[noOfNorthernLat];
    int sizeOfNorthTmpArr = sizeof(northTmpArr) / sizeof(northTmpArr[0]);
    for (int i = 0; i < noOfNorthernLat; i++) {
      printf("Enter the %dth temperature of Northern Latitude : \n", i);
      scanf("%d", &northTmpArr[i]);
      sumOfNorthTmp += northTmpArr[i];
    }
    avgTmpOfNorthLat = sumOfNorthTmp / noOfNorthernLat;
  }

  // For southern part

  int sumOfSouthTmp = 0, avgTmpOfSouthLat;
  printf("Enter the value of SOuthern Latitude (-1 to -90)\n");
  scanf("%d", &southernLat);
  printf("How many temperature do you have for southern lat ?");
  scanf("%d", &noOfSouthernLat);
  if (noOfSouthernLat == 0) {
    printf("NO DATA FOR SOUTHERN HEMISPHERE AT ALT %d\n", southernLat);
  } else {
    int southTmpArr[noOfSouthernLat];
    int sizeOfSouthTmpArr = sizeof(southTmpArr) / sizeof(southTmpArr[0]);
    for (int i = 0; i < noOfSouthernLat; i++) {
      printf("Enter the %dth temperature of Southern Latitude : \n", i);
      scanf("%d", &southTmpArr[i]);
      sumOfSouthTmp += southTmpArr[i];
    }
    avgTmpOfSouthLat = sumOfSouthTmp / noOfSouthernLat;
  }

  if (noOfSouthernLat == 0 || noOfNorthernLat == 0) {
    printf("One of the latitude temperature have no data so, can't compare \n");
  } else {
    int avgTmp = (avgTmpOfNorthLat + avgTmpOfSouthLat) / 2;
    printf("Therefore, the average temperature at %d and % d is %d\n",
           southernLat, northernLat, avgTmp);
    if (avgTmpOfSouthLat > avgTmpOfNorthLat) {
      printf("Southern Hemisphere is warmer \n");
    } else if (avgTmpOfSouthLat < avgTmpOfNorthLat) {
      printf("Northern Hemisphere is warmer\n");
    } else {
      printf("They both have equal temperature\n");
    }
  }
  return 0;
}

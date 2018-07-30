#ifndef __offData_H__
#define __offData_H__

#define OFF_DATA_HEADER 0,8
#define OFF_DATA_VID 8,4
#define OFF_DATA_PID 12,4
#define OFF_DATA_DID 16,24
#define OFF_DATA_OPERATIOFF1 40,2
#define OFF_DATA_OPERATIOFF2 42,2
#define OFF_DATA_OPERATIOFF3 44,2
#define OFF_DATA_LENGTH 46,4

#define OFF_DATA_DATA01 50,2
#define OFF_DATA_DATA02 52,2
#define OFF_DATA_DATA03 54,2
#define OFF_DATA_DATA_(n) 56+(n-4)*1,4

#define OFF_DATA_TRAILER(X) X-4,4


#endif

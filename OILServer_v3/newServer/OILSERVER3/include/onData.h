#ifndef __onData_H__
#define __onData_H__

#define ON_DATA_HEADER 0,8
#define ON_DATA_VID 8,4
#define ON_DATA_PID 12,4
#define ON_DATA_DID 16,24
#define ON_DATA_OPERATION1 40,2
#define ON_DATA_OPERATION2 42,2
#define ON_DATA_OPERATION3 44,2
#define ON_DATA_LENGTH 46,4

#define ON_DATA_DATA01 50,2
#define ON_DATA_DATA02 52,2
#define ON_DATA_DATA03 54,2
#define ON_DATA_DATA_(n) 56+(n-4)*4,4

#define ON_DATA_TRAILER(X) X-4,4


#endif

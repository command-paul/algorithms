#define MU_ASSERT(message, test) do { if (!(test)) return message; } while (0)
#define MU_RUN_TEST(test) do { char *message = test(); tests_run++;if (message) return message; } while (0)
#define COMPARE_INT_ARRAY(message, arr1, arr2,len1,len2) for(i=0; i < len1 && i<len2 ; i++){if(arr1[i]!=arr2[i]) return message;}

extern int tests_run;

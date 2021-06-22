/* Functions used to build the program's menu and the wordlist config*/

/* Function charged to create a beautiful menu x) */
void displayTitle(int8_t max);

/* Function charged to force the user to specify a valid numeric value */
int64_t validNumericValue();

/* Function charged to allocate users' values to the wordlist config */
bool allocateConfig(GEN_CONFIG *wordlistConfig);

/* Function charged to allocate users' values to the password config */
bool allocatePasswdConfig(PASSWD_CONFIG *passwordConfig);
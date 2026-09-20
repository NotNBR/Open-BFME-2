// cl: /O1 /DNDEBUG /MD
// BFME1 T3CommandLineParsers global-flag parser family, adapted using
// BFME2's live command table. -Watchdog at81FBA8 identifies3B94CD (9B).
// Names follow the live token; the global name is descriptive, VA E02D79.
extern bool BFME2WatchdogEnabled;
int parseWatchdog(char *args[],int num) {
    BFME2WatchdogEnabled=true;
    return 1;
}

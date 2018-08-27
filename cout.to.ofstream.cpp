/**
 * Assign cout to a common ofstream variable when needed
 * in this way you can switch between a real file and cout when needed
 */

ofstream    fLog;
string      sLogFilename;
// ...

if (sLogFilename=="") {
    fLog.copyfmt(std::cout);
    fLog.clear(std::cout.rdstate());
    fLog.basic_ios<char>::rdbuf(std::cout.rdbuf());
} else {
    fLog.open(sLogFilename.c_str(), ios::app);
}
if (fLog.fail()) {
    return false;
}

// ...
fLog << "this is a test line" << endl;

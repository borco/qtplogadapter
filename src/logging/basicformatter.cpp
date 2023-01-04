#include "basicformatter.h"

#include <iomanip>

using namespace  logging;

plog::util::nstring BasicFormatter::header() // This method returns a header for a new file. In our case it is empty.
{
    return plog::util::nstring();
}

plog::util::nstring BasicFormatter::format(const plog::Record &record) // This method returns a string from a record.
{
    plog::util::nostringstream ss;
    ss << std::setfill(PLOG_NSTR(' ')) << std::setw(5) << std::left << severityToString(record.getSeverity()) << PLOG_NSTR(" | ");
    ss << record.getMessage() << "\n"; // Produce a simple string with a log message.

    return ss.str();
}

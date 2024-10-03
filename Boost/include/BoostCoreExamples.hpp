#ifndef BOOST_CORE_EXAMPLES_HPP
#define BOOST_CORE_EXAMPLES_HPP

#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

class BoostCoreExamples {
public:
    // Constructor
    BoostCoreExamples();

    // Core functionalities
    void sharedPtrExample();
    void scopedPtrExample();
    void filesystemExample();
    void regexExample();
    void asioExample();
    void threadExample();
};

#endif // BOOST_CORE_EXAMPLES_HPP

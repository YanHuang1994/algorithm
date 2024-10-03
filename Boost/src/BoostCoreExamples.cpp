#include "../include/BoostCoreExamples.hpp"
#include <iostream>
#include <fstream>

// Constructor
BoostCoreExamples::BoostCoreExamples() {}

// Shared Pointer Example
void BoostCoreExamples::sharedPtrExample() {
    boost::shared_ptr<int> ptr1(new int(10));
    boost::shared_ptr<int> ptr2 = ptr1; // Both pointers share ownership
    std::cout << "Shared Pointer Value: " << *ptr1 << std::endl;
    std::cout << "Shared Pointer Use Count: " << ptr1.use_count() << std::endl;
}

// Scoped Pointer Example
void BoostCoreExamples::scopedPtrExample() {
    boost::scoped_ptr<int> ptr(new int(20));
    std::cout << "Scoped Pointer Value: " << *ptr << std::endl;
    // No need to manually delete; scoped_ptr takes care of it
}

// Filesystem Example
void BoostCoreExamples::filesystemExample() {
    boost::filesystem::path path = boost::filesystem::current_path();
    std::cout << "Current Path: " << path << std::endl;
    // Create a new directory for demonstration
    boost::filesystem::create_directory("example_dir");
}

// Regex Example
void BoostCoreExamples::regexExample() {
    std::string text = "Boost Libraries";
    boost::regex pattern("(\\w+)\\s(\\w+)");
    boost::smatch result;
    if (boost::regex_search(text, result, pattern)) {
        std::cout << "Matched: " << result[0] << std::endl;
    }
}

// Asio Example
void BoostCoreExamples::asioExample() {
    boost::asio::io_context io;
    boost::asio::steady_timer timer(io, boost::asio::chrono::seconds(1));
    timer.wait();
    std::cout << "Asio Timer Completed!" << std::endl;
}

// Thread Example
void BoostCoreExamples::threadExample() {
    boost::thread thread([]() {
        std::cout << "Boost Thread Running!" << std::endl;
    });
    thread.join();
}

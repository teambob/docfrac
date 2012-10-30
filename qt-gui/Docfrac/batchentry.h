#ifndef BATCHENTRY_H
#define BATCHENTRY_H

#include <string>

class BatchEntry
{
public:
    typedef enum
    {
        ManualFilename,
        CustomDirectory,
        InputDirectory    // No output path required
    } OutputFilenameGeneration;


    BatchEntry(const std::string &inputFilename, OutputFilenameGeneration outputFilenameGeneration, const std::string &outputPath = "");

    std::string getInputFilename();
    std::string getInputFormat();
    std::string getOutputFilename();
    std::string getOutputFormat();



private:
    std::string inputFile_;
    OutputFilenameGeneration outputFilenameGeneration_;
    std::string outputFormat_;
    std::string outputPath_;


};

#endif // BATCHENTRY_H

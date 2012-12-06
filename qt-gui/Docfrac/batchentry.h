#ifndef BATCHENTRY_H
#define BATCHENTRY_H

#include <string>
#include "FileFormat.h"

class BatchEntry
{
public:
    typedef enum
    {
        ManualFilename,
        CustomDirectory,
        InputDirectory    // No output path required
    } OutputFilenameGeneration;


    BatchEntry(const std::string &inputFilename, OutputFilenameGeneration outputFilenameGeneration, DoxEngine::FileFormat outputFormat, const std::string &outputPath = "");

    std::string getInputFilename() const;
    DoxEngine::FileFormat getInputFormat() const;
    std::string getOutputFilename() const;
    DoxEngine::FileFormat getOutputFormat() const;



private:
    std::string inputFilename_;
    OutputFilenameGeneration outputFilenameGeneration_;
    DoxEngine::FileFormat outputFormat_;
    std::string outputPath_;


};

#endif // BATCHENTRY_H

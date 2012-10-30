#include "batchentry.h"


BatchEntry::BatchEntry(const std::string &inputFilename, BatchEntry::OutputFilenameGeneration outputFilenameGeneration, const std::string &outputPath)
    :inputFile_(inputFilename),outputFilenameGeneration_(outputFilenameGeneration),outputPath_(outputPath)
{
}

std::string BatchEntry::getInputFilename()
{
}

std::string BatchEntry::getInputFormat()
{
}

std::string BatchEntry::getOutputFilename()
{
}

std::string BatchEntry::getOutputFormat()
{
}


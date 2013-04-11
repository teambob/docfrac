#include "batchentry.h"
#include <boost/filesystem.hpp>
#include "ExtensionToFormatMap.h"
#include "FormatToExtensionMap.h"
#include "FileFormat.h"


BatchEntry::BatchEntry(const std::string &inputFilename, BatchEntry::OutputFilenameGeneration outputFilenameGeneration, DoxEngine::FileFormat outputFormat, const std::string &outputPath)
    :inputFilename_(inputFilename),outputFilenameGeneration_(outputFilenameGeneration),outputPath_(outputPath),outputFormat_(outputFormat)
{
}

std::string BatchEntry::getInputFilename() const
{
    return inputFilename_;
}

DoxEngine::FileFormat BatchEntry::getInputFormat() const
{
    using namespace std;
    string inputExtension = boost::filesystem::path(inputFilename_).extension().string();
    if (inputExtension.empty())
        return DoxEngine::FORMAT_UNKNOWN; //TODO: should we throw?
    inputExtension.erase(0,1);

    map<string, DoxEngine::FileFormat> extensions = DoxEngine::getExtensionToFormatMap();
    map<string, DoxEngine::FileFormat>::const_iterator i = extensions.find(inputExtension);
    if (i==extensions.end())
        return DoxEngine::FORMAT_UNKNOWN;
    else
        return i->second;

}

std::string BatchEntry::getOutputFilename() const
{
    if (outputFilenameGeneration_ == ManualFilename)
        return outputPath_;
    else if (outputFilenameGeneration_ == InputDirectory)
    {
        boost::filesystem::path inputPath(inputFilename_);
        std::string basename = boost::filesystem::basename(inputPath);
        boost::filesystem::path outputPath(inputPath.parent_path());
        outputPath /= basename+"."+DoxEngine::getFormatToExtensionMap()[outputFormat_];
        return outputPath.string();
    }
    else if (outputFilenameGeneration_ == CustomDirectory)
    {
        boost::filesystem::path inputPath(inputFilename_);
        std::string basename = boost::filesystem::basename(inputPath);
        boost::filesystem::path outputPath(outputPath_);
        outputPath /= basename+"."+DoxEngine::getFormatToExtensionMap()[outputFormat_];
        return outputPath.string();
    }




    //TODO: other naming systems
}

DoxEngine::FileFormat BatchEntry::getOutputFormat() const
{
    return outputFormat_;
}

void BatchEntry::setOutputFilenameGeneration(BatchEntry::OutputFilenameGeneration outputFilenameGeneration)
{
    outputFilenameGeneration_ = outputFilenameGeneration;
}

void BatchEntry::setOutputFormat(DoxEngine::FileFormat outputFormat)
{
    outputFormat_ = outputFormat;
}

void BatchEntry::setOutputPath(const std::string &outputPath)
{
    outputPath_ = outputPath;
}


#include "about.h"
#include "ui_about.h"
#include <boost/regex.hpp>

About::About(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::About)
{
  ui->setupUi(this);
}

About::~About()
{
  delete ui;
}

void About::showEvent(QShowEvent *)
{
  using namespace std;
  using namespace boost;

  //Subversion keyword substitutions
  string revision("$Revision$");
  string url("$URL$");
  string version("Unknown");

  smatch match;
  if (regex_match(url, match, regex("$URL:.*/tags/([0-9.-]*)/.* $")))
  {
    version = match[1];
  }
  else if (regex_match(url, match, regex("$Revision:.*([0-9]*) $")))
  {
    version = match[1];
  }


  ui->versionNumber->setText(version.c_str());
}

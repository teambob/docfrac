Name: DocFrac
Summary: Command line utility for converting between RTF, HTML and text.
Version: 3.1.1
Release: 1
Copyright: GPL
Source: docfrac-3.1.1.src.tar.gz
URL: http://docfrac.sourceforge.net/
Vendor: Andrew Punch
Packager: Andrew Punch <andrewpunch@bigfoot.com>
Group: Applications/Text

%description
DocFrac is a command line utility for converting:
* RTF to HTML or text
* HTML to RTF or text
* Text to RTF or HTML

Very useful for batch conversions and dynamic websites.

# Automatic prep using setup
%prep
%setup -n docfrac-3.1.1

%build
make

%install
make install

%files
/usr/bin/docfrac
/usr/share/man/man1/docfrac.1

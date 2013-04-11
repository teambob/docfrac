Name: DocFrac
Summary: Command line utility for converting between RTF, HTML and text.
Version: 4.0.1
Release: 1
License: GPL
Source: docfrac-%{version}.src.tar.gz
URL: http://docfrac.sourceforge.net/
Vendor: Andrew Punch
Packager: Andrew Punch <andrew@magneticbooks.com.au>
Group: Applications/Text

%description
DocFrac is a command line utility for converting:
* RTF to HTML or text
* HTML to RTF or text
* Text to RTF or HTML

Very useful for batch conversions and dynamic websites.

# Automatic prep using setup
%prep
%setup -n %{name}-%{version}

%build
make

%install
make install

%files

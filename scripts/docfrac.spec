Name: docfrac
Summary: Command line utility for converting between RTF, HTML and text.
Version: 4.0.1
Release: 1
License: GPL
Source: %{name}-%{version}.src.tar.gz
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
make ROOT="$RPM_BUILD_ROOT"

%install
make install ROOT="$RPM_BUILD_ROOT"

%files
%attr(-, root, root)
/usr/bin/docfrac
/usr/bin/qt-docfrac
/usr/share/man/man1/docfrac.1.gz

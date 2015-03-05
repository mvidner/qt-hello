Name: qt-hello
Version: 1.1
Release: 1
Summary: A trivial Hello World button in Qt
License: MIT
Group: Development/Tools
Packager: Martin Vidner <mvidner@suse.com>
BuildRoot: %{_tmppath}/%{name}-%{version}-root

Source0: main.cpp
Source1: CMakeLists.txt
BuildRequires: cmake
BuildRequires: libqt4-devel

%description

%prep
cp %{SOURCE0} .
cp %{SOURCE1} .

%build
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=%{_prefix} \
      -DLIB=%{_lib} \
      -DCMAKE_C_FLAGS="%{optflags}" \
      -DCMAKE_CXX_FLAGS="%{optflags}" \
      -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_SKIP_RPATH=1 \
      ..
make %{?jobs:-j %jobs} VERBOSE=1

%install
cd build
make install DESTDIR=$RPM_BUILD_ROOT VERBOSE=1

%files
%defattr(-,root,root)
%{_prefix}/bin/helloworld

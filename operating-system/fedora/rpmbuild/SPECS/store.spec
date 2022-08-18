Name:       store 
Version:    0.2 
Release:    1%{?dist} 
Summary:    Store package 
Group:      System Environment/Base 
License:    GPLv3+ 
Source0:    store-0.2.tar.gz 

%description 
Testing package. 

%prep 
%setup -q
 
%install 
cp -rfa * %{buildroot} 

%files 
/* 

 

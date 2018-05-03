#!/usr/bin/env bash

iben=$PWD/cmake-build-debug/iben

echo GATEWAY_INTERFACE="CGI/1.1" REQUEST_METHOD="POST" CONTENT_TYPE="multipart/form-data; boundary=----WebKitFormBoundaryo9JWHtgcpvBesijv" SCRIPT_FILENAME="$iben" "$iben" < ./test_cgi_input.txt

echo

GATEWAY_INTERFACE="CGI/1.1" REQUEST_METHOD="POST" CONTENT_TYPE="multipart/form-data; boundary=----WebKitFormBoundaryo9JWHtgcpvBesijv" SCRIPT_FILENAME="$iben" "$iben" < ./test_cgi_input.txt

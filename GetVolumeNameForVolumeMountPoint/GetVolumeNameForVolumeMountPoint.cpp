//  Copyright 2022 VMWare, Inc. All Rights Reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http ://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#include "stdafx.h"
#include <CommonUtils.h>

int wmain(int argc, LPCWSTR argv[])
{
	wprintf(L"\nGetVolumeNameForVolumeMountPoint Win32 API Wrapper\n");
	wprintf(L"Copyright (C) 2022 VMWare, Inc.\n\n");

	if (argc < 2)
	{
		wprintf(L"Usage: %ls <mount point>\n", argv[0]);
		wprintf(L"  mount point must end with a backslash. Ex: c:\\");
		return 1;
	}

	// Volume name is a GUID - much less than max_path
	wchar_t output[_MAX_PATH];

	wprintf(L"Mount point: %ls\n", argv[1]);

	if (GetVolumeNameForVolumeMountPointW(argv[1], output, _countof(output)))
	{
		wprintf(L"Volume name: %ls\n", output);
	}
	else
	{
		wprintf(L"GetVolumeNameForVolumeMountPoint failed with error %d\n", GetLastError());
	}
	
	return 0;
}


/*
 * ZipCommon.h -- IO on .zip files using minizip and zlib
 * Version 1.0.0.2, 22.01.2017
 * part of the CppZip project - (https://github.com/flo2k/CppZip)
 *
 * Created: 06.12.2012, Florian Künzner
 *
 * Copyright (C) 2012-2013 Florian Künzner and Andreas Bauer (CppZip) (https://github.com/flo2k/CppZip)
 * Copyright (C) 2014-2017 Florian Künzner (CppZip) (https://github.com/flo2k/CppZip)
 *
 * ---------------------------------------------------------------------------
 *
 * Condition of use and distribution are the same than minizip and zlib :
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 * ---------------------------------------------------------------------------
 *
 */

#ifndef CPPZIP_ZIPCOMMON_H_
#define CPPZIP_ZIPCOMMON_H_

#include <string>

/* Defined already in minizip's zip.c. Placed here to use as default parameter in Zip and Unzip*/
#ifndef VERSIONMADEBY
	/*! brief This version is used bye minizip (zip.c) to create files inside the zip */
	#define VERSIONMADEBY   (0x0) /* platform dependent */
#endif

namespace cppzip {

/*
 * InnerZipFileInfo contains all Infos to save a file into zip.
 */
struct InnerZipFileInfo
{
	InnerZipFileInfo(void);

	std::string fileName;
	std::string extraField;
	std::string comment;
	unsigned int time_sec;                    /* seconds after the minute - [0,59] */
	unsigned int time_min;                    /* minutes after the hour - [0,59] */
	unsigned int time_hour;                   /* hours since midnight - [0,23] */
	unsigned int time_day_of_month;           /* day of the month - [1,31] */
	unsigned int time_month;                  /* months since January - [0,11] */
	unsigned int time_year;                   /* years - [1980..2044] */
	unsigned long dosDate;                    /* if dos_date == 0, tmu_date is used */
	unsigned long crc;                        /* crc-32 */
	unsigned long compressed_size;            /* compressed size */
	unsigned long uncompressed_size;          /* uncompressed size */

	unsigned long internal_fileAttributes;
	unsigned long external_fileAttributes;
};

} //cppzip

#endif /* CPPZIP_ZIPCOMMON_H_ */

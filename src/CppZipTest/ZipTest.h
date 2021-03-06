/*!
 * ZipTest.h -- Tests Zip.h from CppZip
 * Version 1.0.0.2, 22.01.2017
 * part of the CppZip project - (https://github.com/flo2k/CppZip)
 *
 * Created: 15.11.2011, Florian Künzner
 *
 * Copyright (C) 2011 Florian Künzner (CppZip)
 * Copyright (C) 2012 Florian Künzner and Andreas Bauer (CppZip) (https://github.com/flo2k/CppZip)
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

#ifndef CPPZIP_ZIPTEST_H_
#define CPPZIP_ZIPTEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <memory>
#include <string>

namespace cppzip {

//forward declaration
class Zip;

class ZipTest : public CppUnit::TestFixture {

	CPPUNIT_TEST_SUITE(ZipTest);
		CPPUNIT_TEST(test_isOpenedWithNonOpenedZipFile);

		CPPUNIT_TEST(test_openANonExistingZipFile);
		CPPUNIT_TEST(test_openAExistingZipFile);
		CPPUNIT_TEST(test_openAExistingWriteProtectedZipFile);
		CPPUNIT_TEST(test_openAppendToZip);
		CPPUNIT_TEST(test_openAppendToZipWithFileAlreadyExisting);

		CPPUNIT_TEST(test_closeAZipFile);
		CPPUNIT_TEST(test_closeWhenNoZipFileIsOpened);

		CPPUNIT_TEST(test_addFile);
		CPPUNIT_TEST(test_addFile_WhenFileNotExists);
		CPPUNIT_TEST(test_addFile_WhenFileNameAlreadyExists);
		CPPUNIT_TEST(test_addFile_WithNotPreservePath);
		CPPUNIT_TEST(test_addFile_WithDestinationFile);
		CPPUNIT_TEST(test_addFile_WithDestinationFile_WhenFileNotExists);
		CPPUNIT_TEST(test_addFile_WithDestinationFile_WithFileNameIsEmpty);
		CPPUNIT_TEST(test_addFile_WithDestinationFile_WhenFileNameAlreadyExists);

		CPPUNIT_TEST(test_addFile_Content);
		CPPUNIT_TEST(test_addFile_Content_FromAString);
		CPPUNIT_TEST(test_addFile_Content_WithEmptyContent);
		CPPUNIT_TEST(test_addFile_Content_WithSubFoldersFileName);
		CPPUNIT_TEST(test_addFile_Content_IfZipIsNotOpened);

		CPPUNIT_TEST(test_addFiles);
		CPPUNIT_TEST(test_addFiles_WithNotPreservePath);
		CPPUNIT_TEST(test_addFiles_WhenOneFileNotExists);

		CPPUNIT_TEST(test_addEmptyFolder);
		CPPUNIT_TEST(test_addEmptyFolder_WithUmlaut);
		CPPUNIT_TEST(test_addEmptyFolder_WhenFolderAlreadyExists);
		CPPUNIT_TEST(test_addEmptyFolder_WithSubFolders);
		CPPUNIT_TEST(test_addEmptyFolder_WithSubFolders_WhenAFolderPartAlreadyExists);
		CPPUNIT_TEST(test_addEmptyFolder_WithSubFolders_WindowsStyle);

		CPPUNIT_TEST(test_addFolder_recursive);
		CPPUNIT_TEST(test_addFolder_notRecursive);
		CPPUNIT_TEST(test_addFolder_notPreservesPath);
		CPPUNIT_TEST(test_addFolder_notPreservesPath_and_notRecursive);

		CPPUNIT_TEST(test_deleteFile);
		CPPUNIT_TEST(test_deleteFiles);
		CPPUNIT_TEST(test_deleteFolder);
		CPPUNIT_TEST(test_deleteFolders);
		CPPUNIT_TEST(test_deleteFile_WhenFileNotExists);
		CPPUNIT_TEST(test_deleteFile_WhenTemparyFileCouldntCreated);
		CPPUNIT_TEST(test_deleteFile_CheckOtherFileContent);

		CPPUNIT_TEST(test_replaceFile);
		CPPUNIT_TEST(test_replaceFile_WhenFileNotExistsInZip);
		CPPUNIT_TEST(test_replaceFile_WhenFileNotExistsOnFileSystem);
		CPPUNIT_TEST(test_replaceFile_Content);

		CPPUNIT_TEST(test_addFile_WithPasswordProtection);
		CPPUNIT_TEST(test_addFile_Content_WithPasswordProtection);
		CPPUNIT_TEST(test_addFile_Content_FromAString_WithPasswordProtection);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp(void);
	void tearDown(void);

public:
	void test_isOpenedWithNonOpenedZipFile(void);

	void test_openANonExistingZipFile(void);
	void test_openAExistingZipFile(void);
	void test_openAExistingWriteProtectedZipFile(void);
	void test_openAppendToZip(void);
	void test_openAppendToZipWithFileAlreadyExisting(void);

	void test_closeAZipFile(void);
	void test_closeWhenNoZipFileIsOpened(void);

	void test_addFile(void);
	void test_addFile_WhenFileNotExists(void);
	void test_addFile_WhenFileNameAlreadyExists(void);
	void test_addFile_WithNotPreservePath(void);
	void test_addFile_WithDestinationFile(void);
	void test_addFile_WithDestinationFile_WhenFileNotExists(void);
	void test_addFile_WithDestinationFile_WithFileNameIsEmpty(void);
	void test_addFile_WithDestinationFile_WhenFileNameAlreadyExists(void);

	void test_addFile_Content(void);
	void test_addFile_Content_FromAString(void);
	void test_addFile_Content_WithEmptyContent(void);
	void test_addFile_Content_WithSubFoldersFileName(void);
	void test_addFile_Content_IfZipIsNotOpened(void);

	void test_addFiles(void);
	void test_addFiles_WithNotPreservePath(void);
	void test_addFiles_WhenOneFileNotExists(void);

	void test_addEmptyFolder(void);
	void test_addEmptyFolder_WithUmlaut(void);
	void test_addEmptyFolder_WhenFolderAlreadyExists(void);
	void test_addEmptyFolder_WithSubFolders(void);
	void test_addEmptyFolder_WithSubFolders_WhenAFolderPartAlreadyExists(void);
	void test_addEmptyFolder_WithSubFolders_WindowsStyle(void);

	void test_addFolder_recursive(void);
	void test_addFolder_notRecursive(void);
	void test_addFolder_notPreservesPath(void);
	void test_addFolder_notPreservesPath_and_notRecursive(void);

	void test_deleteFile(void);
	void test_deleteFiles(void);
	void test_deleteFolder(void);
	void test_deleteFolders(void);
	void test_deleteFile_WhenFileNotExists(void);
	void test_deleteFile_WhenTemparyFileCouldntCreated(void);
	void test_deleteFile_CheckOtherFileContent(void);

	void test_replaceFile(void);
	void test_replaceFile_WhenFileNotExistsInZip(void);
	void test_replaceFile_WhenFileNotExistsOnFileSystem(void);
	void test_replaceFile_Content(void);

	void test_addFile_WithPasswordProtection(void);
	void test_addFile_Content_WithPasswordProtection(void);
	void test_addFile_Content_FromAString_WithPasswordProtection(void);

private:
	bool containsFile(const std::string & zipFileName, const std::string & fileName);
	bool containsFolder(const std::string & zipFileName, const std::string & folderName);
	int numFilesInZip(const std::string & zipFileName);
	void createFolder(const std::string & fileName);
	void createFile(const std::string & fileName, const std::string & content);
	void copyFile(const std::string & src, const std::string & dest);
	std::vector<unsigned char> getFileContent(const std::string & zipFile, const std::string & fileName, const std::string & password = "");
	std::string getFileContentAsString(const std::string & zipFile, const std::string & fileName, const std::string & password = "");

private:
	std::shared_ptr<Zip> zip;

	std::string testZipsFolder;
	std::string zipFile;
	std::string zipFileWithUmlaut;
	std::string anotherZipFile;
	std::string notExistingZipFile;
	std::string writeProtectedZipFile;
	std::string tempFolder;
	std::string picsFolder;
	std::string fileInsideZip;
	std::string fileInsideZipWithUmlaut;
	std::string fileInsideZipThatDoesNotExist;
	std::string fileInsideZipJpg;
	std::string anotherFileName;
	std::string readMeFileName;
	std::string notExistingFileName;
	std::string zipFileFor_deleteAndReplace;
	std::string folderNameInsideZip;
};

} //cppzip

#endif /* CPPZIP_ZIPTEST_H_ */

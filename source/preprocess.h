#ifndef PREPROCESśS_H
#define PREPROCESS_H

#include <vector>
#include <string>
#include <cstdlib>
#include <shlobj.h>
#include <iostream>
#include <windows.h>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

class Preprocess
{
public:
    string create_pixels_txt(vector<string>& folder_name)
    {
        string folderPath = browseFolder("Choose your folder");
        if (!folderPath.empty())
        {
            for (const auto& entry : fs::directory_iterator(folderPath)) if (entry.is_directory()) folder_name.push_back(entry.path().filename().string());
            for (int i = 0; i < folder_name.size(); ++i)
            {
                string folder_path  = folderPath + "\\" + folder_name[i];
                string command = "python preprocess.py \"" + folder_path + "\" " + folder_name[i];
                int result = system(command.c_str());
                if (result != 0) cout << "Python preprocessing failed.\n";
            }
            cout << "Folder Created..." << endl;
            cout << endl << endl;
        }
        else cout << "No folder selected or canceled." << endl;
        return folderPath;
    }
    string browseFolder(const std::string& title = "Select a Dataset")
    {
        BROWSEINFO bi = { 0 };
        bi.lpszTitle = title.c_str();
        bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
        LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
        char path[MAX_PATH];
        if (pidl != 0)
            if (SHGetPathFromIDList(pidl, path))
                return std::string(path);
        return "";
    }
    void show(vector<string>& folder_name)
    {
        for (int i = 0; i < folder_name.size(); ++i)
        {
            cout << folder_name[i] << endl;
        }
    }
};
#endif
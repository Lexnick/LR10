#include <iostream>
#include <string>
#include <filesystem>

int main() {
    int Command;
    std::string Temp1;
    std::string Temp;
    std::string Cycle;
    bool Continue = true;
    bool Check = true;
    std::filesystem::path File;
    std::filesystem::path File1;
    while (Continue) {
        std::cout << "Enter the command number. To see the list of commands - input 0." << std::endl;
        std::cin >> Command;
        switch (Command) {
            case 0:
                std::cout << "List of commands:\n"
                          << "1.Current path\n"
                          << "2.Directory contents\n"
                          << "3.Directory creation\n"
                          << "4.File size\n"
                          << "5.Copy file\n"
                          << "6.Delete file\n"
                          << "7.Delete a directory with files\n"
                          << "8.Move through directories\n"
                          << "9.Rename files and directories\n"
                          << "10.Move files and directories\n" << std::endl;
                break;
            case 1:
                std::cout << "Current path is " << std::filesystem::current_path() << std::endl;
                break;
            case 2:
                std::cout << "Enter the name of the directory which content you want to see." << std::endl;
                std::cin >> Temp;
                for (auto &iter: std::filesystem::directory_iterator(Temp))
                    std::cout << iter.path().filename() << std::endl;
                break;
            case 3:
                std::cout << "Enter the directory name." << std::endl;
                std::cin >> Temp;
                Check = true;
                for (auto &iter: std::filesystem::directory_iterator(std::filesystem::current_path()))
                    if (iter.path().filename() == Temp) {
                        std::cout << "There is already a directory with the same name." << std::endl;
                        Check = false;
                    };
                if (Check) {
                    std::filesystem::create_directory(Temp);
                    std::cout << "Directory \"" << Temp << "\" was created." << std::endl;
                }

                break;
            case 4:
                std::cout << "Enter the file name" << std::endl;
                std::cin >> Temp;
                std::cout << "File size = " << std::filesystem::file_size(Temp) << " byte(s)" << std::endl;
                break;
            case 5:
                std::cout << "Enter the name of the file you want to copy" << std::endl;
                std::cin >> Temp;
                std::cout << "Enter the name of the new file. Make sure extensions match" << std::endl;
                std::cin >> Temp1;
                std::filesystem::copy_file(Temp, Temp1);
                std::cout << "File was copied, the name of the new file is \"" << Temp1 << "\"" << std::endl;
                break;
            case 6:
                std::cout << "Enter the name of the file you want to remove" << std::endl;
                std::cin >> Temp;
                std::filesystem::remove(Temp);
                std::cout << "File \"" << Temp << "\" was removed" << std::endl;
                break;
            case 7:
                std::cout << "Enter the name of the directory you want to remove" << std::endl;
                std::cin >> Temp;
                std::filesystem::remove_all(Temp);
                std::cout << "Directory \"" << Temp << "\" was removed" << std::endl;
                break;
            case 8:
                std::cout << "Do you want to go up or down? (Enter Up/Down)" << std::endl;
                std::cin >> Temp1;
                if ((Temp1 == "Up") || (Temp1 == "up")) {
                    std::filesystem::current_path(std::filesystem::current_path().parent_path());
                    std::cout << "Current path is " << std::filesystem::current_path() << std::endl;
                } else if ((Temp1 == "Down") || (Temp1 == "down")) {
                    std::cout << "Enter the name of the directory you want to go to" << std::endl;
                    std::cin >> Temp;
                    std::filesystem::current_path(Temp);
                    std::cout << "Current path is " << std::filesystem::current_path() << std::endl;
                } else std::cout << "Invalid command." << std::endl;
                break;
            case 9:
                std::cout << "Enter the directory/file you want to rename" << std::endl;
                std::cin >> Temp;
                std::cout << "Enter the new name" << std::endl;
                std::cin >> Temp1;
                std::filesystem::rename(Temp, Temp1);
                std::cout << "\"" << Temp << "\"  was renamed. New name: \"" << Temp1 << "\"" << std::endl;
                break;
            case 10:
                std::cout << "Enter the name of directory/file you want to move" << std::endl;
                std::cin >> Temp;
                std::cout << "Enter the new path (including the name of the new file. Ex: to/file2.txt)" << std::endl;
                std::cin >> Temp1;
                File=Temp;
                File1=Temp1;
                std::filesystem::rename(File,File1);
                std::cout<<'\"'<<Temp<<"\" was moved. New path is \""<<Temp1<<'\"'<<std::endl;
                break;
            default:
                std::cout << "Invalid command." << std::endl;
        }
        std::cout << "Do you want co continue? (Yes/No)" << std::endl;
        std::cin >> Cycle;
        if ((Cycle == "Yes") || (Cycle == "yes") || (Cycle == "y") || Cycle == "Y")
            Continue = true;
        else Continue = false;
    }
    return 0;
}

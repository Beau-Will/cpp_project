#include <bits/stdc++.h>
#include <cstdlib>
#include <fstream>

using namespace std;

// 编译指定的源文件
bool compile(const string& source, const string& executable) {
  string command = "g++ -o " + executable + " " + source + " -O2 -std=c++17";
  int result = system(command.c_str());
  return result == 0;
}

// 读取文件内容
string read_file(const string& filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    return "[文件读取失败: " + filename + "]";
  }
  string content;
  string line;
  while (getline(file, line)) {
    content += line + "\n";
  }
  file.close();
  if (!content.empty()) {
    content.pop_back(); // 移除最后一个换行符
  }
  return content;
}

// 比较两个文件内容是否相同
bool compare_files(const string& file1, const string& file2) {
  string content1 = read_file(file1);
  string content2 = read_file(file2);
  return content1 == content2;
}

// 打印分隔线
void print_separator(int width = 60) {
  cout << "\n";
  for (int i = 0; i < width; i++) {
    cout << "=";
  }
  cout << "\n";
}

int main() {
  // 设置控制台为UTF-8编码（适用于Windows 10/11）
  system("chcp 65001 > nul");

  cout << "正在启动对拍程序...\n";
  print_separator();

  // 编译三个程序
  cout << "编译 generator.cpp...\n";
  if (!compile("generator.cpp", "generator.exe")) {
    cout << "错误: 编译 generator.cpp 失败!\n";
    system("pause");
    return 1;
  }

  cout << "编译 std.cpp...\n";
  if (!compile("std.cpp", "std.exe")) {
    cout << "错误: 编译 std.cpp 失败!\n";
    system("pause");
    return 1;
  }

  cout << "编译 brute.cpp...\n";
  if (!compile("brute.cpp", "brute.exe")) {
    cout << "错误: 编译 brute.cpp 失败!\n";
    system("pause");
    return 1;
  }

  print_separator();
  cout << "所有程序编译成功! 开始对拍测试...\n\n";

  int test_count = 0;
  const int max_tests = 1000000; // 最大测试次数，防止无限循环

  while (test_count < max_tests) {
    test_count++;

    // 打印当前测试信息
    cout << "测试 #" << test_count;

    // 生成随机输入
    system("generator.exe > in.txt");

    // 运行标准解法
    system("std.exe < in.txt > std_out.txt");

    // 运行暴力解法
    system("brute.exe < in.txt > brute_out.txt");

    // 比较结果
    if (compare_files("std_out.txt", "brute_out.txt")) {
      cout << "  [AC]\n";
    } else {
      cout << "  [WA]\n";
      print_separator();

      // 输出错误信息
      cout << "发现不一致的输出!\n\n";

      // 输出输入数据
      cout << "输入数据 (in.txt):\n";
      cout << read_file("in.txt") << "\n\n";

      // 输出标准解法结果
      cout << "标准解法输出 (std_out.txt):\n";
      cout << read_file("std_out.txt") << "\n\n";

      // 输出暴力解法结果
      cout << "暴力解法输出 (brute_out.txt):\n";
      cout << read_file("brute_out.txt") << "\n\n";

      print_separator();
      cout << "对拍终止于第 " << test_count << " 组测试\n";

      // 保存错误案例
      string error_dir = "error_case_" + to_string(test_count);
      system(("mkdir " + error_dir + " 2>nul").c_str());
      system(("copy in.txt " + error_dir + " >nul").c_str());
      system(("copy std_out.txt " + error_dir + " >nul").c_str());
      system(("copy brute_out.txt " + error_dir + " >nul").c_str());
      cout << "错误案例已保存到文件夹: " << error_dir << "\n";

      system("pause");
      return 0;
    }

    // 每100组测试显示一次进度
    if (test_count % 100 == 0) {
      cout << "已通过 " << test_count << " 组测试\n";
    }

    // 清空缓冲区，立即显示输出
    cout.flush();
  }

  print_separator();
  cout << "通过所有 " << test_count << " 组测试!\n";
  cout << "程序看起来是正确的！\n";

  system("pause");
  return 0;
}
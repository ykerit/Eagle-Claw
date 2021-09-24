import os
root_path = os.path.abspath(os.path.join(os.path.dirname(__file__),os.path.pardir))
dll = "GRender"
app = "Sandbox"

def get_format_file(path):
    filelist = []
    for root, _, files in os.walk(path):
        if "third_party" in root: continue
        for filepath in files:
            if os.path.splitext(filepath)[1] == ".h" or os.path.splitext(filepath)[1] == ".cpp":
                print(filepath)
                filelist.append(os.path.join(root, filepath))
    return filelist

list = os.listdir(os.path.join(root_path, dll))
print(root_path)

dll_files = get_format_file(os.path.join(root_path, dll))
app_files = get_format_file(os.path.join(root_path, app))

all_files = dll_files + app_files

for file in all_files:
    import sys
    cmd = ''
    if sys.platform == 'darwin' or sys.platform == 'linux':
        cmd = 'clang-format -i ' + file
    else:
        cmd = 'clang-format.exe -i ' + file
    os.popen(cmd)

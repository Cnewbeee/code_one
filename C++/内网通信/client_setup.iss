[Setup]
AppName=内网通信客户端
AppVersion=1.0
DefaultDirName={pf}\内网通信客户端
DefaultGroupName=内网通信客户端
OutputDir=output
OutputBaseFilename=ClientSetup
Compression=lzma
SolidCompression=yes

[Files]
Source: "client.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "vcredist_x86.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall

[Icons]
Name: "{group}\内网通信客户端"; Filename: "{app}\client.exe"
Name: "{commondesktop}\内网通信客户端"; Filename: "{app}\client.exe"

[Run]
Filename: "{tmp}\vcredist_x86.exe"; Parameters: "/install /quiet /norestart"; StatusMsg: "正在安装运行库..."
Filename: "{app}\client.exe"; Description: "启动客户端"; Flags: postinstall nowait skipifsilent

[Code]
function InitializeSetup(): Boolean;
begin
  if not IsAdminLoggedOn then
  begin
    MsgBox('请使用管理员权限运行安装程序', mbError, MB_OK);
    Result := False;
  end
  else
    Result := True;
end;

;��� ����������
#define Name "SpaceWar"
;������
#define Version "1.0"
;���������
#define Publisher "Vladislav Chuprakov"
;���� ������������
#define URL "https://vk.com/vladchuprakov"
;�������� .���
#define ExeName "SpaceWar.exe"

[Setup]

;���������� ���
AppId={{E8DF6E16-3A35-452A-9D4C-BCED32EA4EAA}}

;������ ��-��, ������������ ��� ���������
AppName={#Name}
AppVersion={#Version}
AppPublisher={#Publisher}
AppPublisherURL={#URL}
AppSupportURL={#URL}
AppUpdatesURL={#URL}

;���� ���������
DefaultDirName={pf}\{#Name}
;��� � ���� ����
DefaultGroupName={#Name}

;�������,���� ����� ������� ��������� setup � ��� ������������ �����
OutputDir=C:\Git\SpaceWar\Installer\output
OutputBaseFilename=SpaceWar

;���� ������
SetupIconFile=C:\Git\SpaceWar\Textures\SpaceWarIconforInstaller.ico

;��������� ������
Compression=lzma
SolidCompression=yes

[Languages]
;������������� ����� ��� �������� ��������� � ����������
Name: "english"; MessagesFile: "compiler:Default.isl"; LicenseFile: "License_ENG.txt"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"; LicenseFile: "License_RUS.txt"

[Tasks]
;�������� ������ �� ������� �����
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
;����������� ����
Source: "C:\Builds\fjkjfjfs\Debug\SpaceWar.exe"; DestDir: "{app}"; Flags: ignoreversion

;������������� �������
Source: "C:\Git\SpaceWar\Textures\*"; DestDir: "{app}\Textures\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Git\SpaceWar\Fonts\*"; DestDir: "{app}\Fonts\"; Flags: ignoreversion recursesubdirs createallsubdirs

;����� VS
Source: "C:\Git\SpaceWar\Installer\VC_redist.x64.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall

[Icons]

Name: "{group}\{#Name}"; Filename: "{app}\{#ExeName}"

Name: "{commondesktop}\{#Name}"; Filename: "{app}\{#ExeName}"; Tasks: desktopicon

[Run]
;������ ������� ����� �����������
Filename: {tmp}\VC_redist.x64.exe; Parameters: "/q:a /c:""install /l /q"""; StatusMsg: VS redistributable package is installed. Please wait... 
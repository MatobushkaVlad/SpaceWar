;Имя приложения
#define Name "SpaceWar"
;Версия
#define Version "1.0"
;Создатель
#define Publisher "Vladislav Chuprakov"
;Сайт разработчика
#define URL "https://vk.com/vladchuprakov"
;Название .ехе
#define ExeName "SpaceWar.exe"

[Setup]

;Уникальный код
AppId={{E8DF6E16-3A35-452A-9D4C-BCED32EA4EAA}}

;Прочая ин-фа, отображаемая при установке
AppName={#Name}
AppVersion={#Version}
AppPublisher={#Publisher}
AppPublisherURL={#URL}
AppSupportURL={#URL}
AppUpdatesURL={#URL}

;Путь установки
DefaultDirName={pf}\{#Name}
;Имя в меню Пуск
DefaultGroupName={#Name}

;Каталог,куда будет записан собранный setup и имя исполняемого файла
OutputDir=C:\Git\SpaceWar\Installer\output
OutputBaseFilename=SpaceWar

;Файл иконки
SetupIconFile=C:\Git\SpaceWar\Textures\SpaceWarIconforInstaller.ico

;Параметры сжатия
Compression=lzma
SolidCompression=yes

[Languages]
;Устанавливаем языки для процесса установки и соглашения
Name: "english"; MessagesFile: "compiler:Default.isl"; LicenseFile: "License_ENG.txt"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"; LicenseFile: "License_RUS.txt"

[Tasks]
;Создание иконки на рабочем столе
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
;Исполняемый файл
Source: "C:\Builds\fjkjfjfs\Debug\SpaceWar.exe"; DestDir: "{app}"; Flags: ignoreversion

;Прилагающиеся ресурсы
Source: "C:\Git\SpaceWar\Textures\*"; DestDir: "{app}\Textures\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Git\SpaceWar\Fonts\*"; DestDir: "{app}\Fonts\"; Flags: ignoreversion recursesubdirs createallsubdirs

;Файлы VS
Source: "C:\Git\SpaceWar\Installer\VC_redist.x64.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall

[Icons]

Name: "{group}\{#Name}"; Filename: "{app}\{#ExeName}"

Name: "{commondesktop}\{#Name}"; Filename: "{app}\{#ExeName}"; Tasks: desktopicon

[Run]
;Секция запуска после инсталляции
Filename: {tmp}\VC_redist.x64.exe; Parameters: "/q:a /c:""install /l /q"""; StatusMsg: VS redistributable package is installed. Please wait... 
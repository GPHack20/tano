Delete "$INSTDIR\tano-editor.exe"
Delete "$INSTDIR\LICENSE.GPL.TXT"
Delete "$INSTDIR\libgcc_s_dw2-1.dll"
Delete "$INSTDIR\mingwm10.dll"
Delete "$INSTDIR\QtCore4.dll"
Delete "$INSTDIR\QtGui4.dll"
Delete "$INSTDIR\QtNetwork4.dll"
Delete "$INSTDIR\QtSvg4.dll"
Delete "$INSTDIR\QtXml4.dll"

Delete "$INSTDIR\lang\cs_CZ.qm"
Delete "$INSTDIR\lang\fr_FR.qm"
Delete "$INSTDIR\lang\ru_RU.qm"
Delete "$INSTDIR\lang\sl_SI.qm"
Delete "$INSTDIR\lang\uk_UA.qm"

Delete "$INSTDIR\imageformats\qgif4.dll"
Delete "$INSTDIR\imageformats\qico4.dll"
Delete "$INSTDIR\imageformats\qjpeg4.dll"
Delete "$INSTDIR\imageformats\qmng4.dll"
Delete "$INSTDIR\imageformats\qsvg4.dll"
Delete "$INSTDIR\imageformats\qtiff4.dll"

RMDir "$INSTDIR\imageformats"
RMDir "$INSTDIR\lang"

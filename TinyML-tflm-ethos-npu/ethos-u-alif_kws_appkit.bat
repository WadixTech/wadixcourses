cp -r prebuild_images/images/*  APFW0001-app-release-exec-windows-SE_FW_1.107.00_DEV/app-release-exec\build\images/
cd  APFW0001-app-release-exec-windows-SE_FW_1.107.00_DEV\app-release-exec
app-gen-toc -f ..\..\prebuild_images\config\kws_demo.json
app-write-mram -p

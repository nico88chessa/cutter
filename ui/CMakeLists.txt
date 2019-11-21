SET(SUB_FOLDERS
    logic
    qml
    )

FOREACH(item ${SUB_FOLDERS})
    MESSAGE("Folder: " ${item})
    ADD_SUBDIRECTORY(${item})
ENDFOREACH(item)

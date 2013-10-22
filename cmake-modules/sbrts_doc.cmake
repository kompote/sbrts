INCLUDE(FindDoxygen)

IF(DOXYGEN)
	SET(DOC_CONFIG_DIR ${SBRTS_DOC_DIR})
	SET(DOC_CONFIG_FILE ${DOC_CONFIG_DIR}/Doxyfile)
	IF(UNIX)
		ADD_CUSTOM_TARGET(doc
		COMMAND ${DOXYGEN} ${DOC_CONFIG_FILE}
		COMMAND rm -rf ${DOC_CONFIG_DIR}/html
		COMMAND mv html ${DOC_CONFIG_DIR}
		)
	ENDIF(UNIX)
	IF(WIN32)
		ADD_CUSTOM_TARGET(doc
		COMMAND ${DOXYGEN} ${DOC_CONFIG_FILE}
		COMMAND move html ${DOC_CONFIG_DIR}
		)
	ENDIF(WIN32)
ELSE(DOXYGEN)
	MESSAGE("Doxygen not found - Target doc not available")
ENDIF(DOXYGEN)

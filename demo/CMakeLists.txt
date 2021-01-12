cmake_minimum_required(VERSION 2.8.9)

set(ENCRYPT_DATA_DEMO encryptDataDemo)
set(ENCRYPT_SPDU_DEMO encryptSpduDemo)
set(SIGN_MESSAGE_DEMO_ASYNC signMessageDemoAsync)
set(SIGN_MESSAGE_DEMO signMessageDemo)
set(SYMMETRIC_KEY_ENCRYPT_DATA_DEMO symmetricKeyEncryptDataDemo)
set(SYMMETRIC_KEY_ENCRYPT_SPDU_DEMO symmetricKeyEncryptSpduDemo)

add_executable (${ENCRYPT_DATA_DEMO} encryptDataDemo.c)
add_executable (${ENCRYPT_SPDU_DEMO} encryptSpduDemo.c)
add_executable (${SIGN_MESSAGE_DEMO_ASYNC} signMessageDemoAsync.c)
add_executable (${SIGN_MESSAGE_DEMO} signMessageDemo.c)
add_executable (${SYMMETRIC_KEY_ENCRYPT_DATA_DEMO} symmetricKeyEncryptDataDemo.c)
add_executable (${SYMMETRIC_KEY_ENCRYPT_SPDU_DEMO} symmetricKeyEncryptSpduDemo.c)

target_link_libraries(${ENCRYPT_DATA_DEMO} viicsec)
target_link_libraries(${ENCRYPT_SPDU_DEMO} viicsec)
target_link_libraries(${SIGN_MESSAGE_DEMO_ASYNC} viicsec)
target_link_libraries(${SIGN_MESSAGE_DEMO} viicsec)
target_link_libraries(${SYMMETRIC_KEY_ENCRYPT_DATA_DEMO} viicsec)
target_link_libraries(${SYMMETRIC_KEY_ENCRYPT_SPDU_DEMO} viicsec)

# install to target
install ( TARGETS ${ENCRYPT_DATA_DEMO}
          ${ENCRYPT_SPDU_DEMO}
          ${SIGN_MESSAGE_DEMO_ASYNC}
          ${SIGN_MESSAGE_DEMO}
          ${SYMMETRIC_KEY_ENCRYPT_DATA_DEMO}
          ${SYMMETRIC_KEY_ENCRYPT_SPDU_DEMO}
          RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} )

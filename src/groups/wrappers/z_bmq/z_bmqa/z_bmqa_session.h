/**
 * @file z_bmqa_session.h
 * @brief This file contains the declaration of the z_bmqa_Session structure and related functions.
 */

#ifndef INCLUDED_Z_BMQA_SESSION
#define INCLUDED_Z_BMQA_SESSION

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>
#include <z_bmqa_closequeuestatus.h>
#include <z_bmqa_configurequeuestatus.h>
#include <z_bmqa_confirmeventbuilder.h>
#include <z_bmqa_event.h>
#include <z_bmqa_message.h>
#include <z_bmqa_messageevent.h>
#include <z_bmqa_messageeventbuilder.h>
#include <z_bmqa_messageproperties.h>
#include <z_bmqa_openqueuestatus.h>
#include <z_bmqa_queueid.h>
#include <z_bmqt_sessionoptions.h>
#include <z_bmqt_uri.h>


typedef void (*z_bmqa_OnSessionEventCb)(
    const z_bmqa_SessionEvent* sessionEvent,
    void*                      data);

typedef void (*z_bmqa_OnMessageEventCb)(
    const z_bmqa_MessageEvent* messageEvent,
    void*                      data);

typedef struct z_bmqa_SessionEventHandlers {
    z_bmqa_OnSessionEventCb onSessionEvent;
    z_bmqa_OnMessageEventCb onMessageEvent;
} z_bmqa_SessionEventHandlers;


typedef struct z_bmqa_Session z_bmqa_Session;

/**
 * @brief Deletes a Session object.
 * 
 * @param session_obj Pointer to the Session object to be deleted.
 * 
 * @return Returns 0 upon successful deletion.
 */
int z_bmqa_Session__delete(z_bmqa_Session** session_obj);

/**
 * @brief Creates a new Session object.
 * 
 * @param session_obj Pointer to store the created Session object.
 * @param options Pointer to the SessionOptions object for configuring the session.
 * 
 * @return Returns 0 upon successful creation.
 */
int z_bmqa_Session__create(z_bmqa_Session**             session_obj,
                           const z_bmqt_SessionOptions* options);

/**
 * @brief Creates a new Session object asynchronously.
 * 
 * @param session_obj Pointer to store the created Session object.
 * @param eventHandler Event handler for handling session events.
 * @param options Pointer to the SessionOptions object for configuring the session.
 * 
 * @return Returns 0 upon successful creation.
 */
int z_bmqa_Session__createAsync(z_bmqa_Session**             session_obj,
                                z_bmqa_SessionEventHandlers  eventHandlers,
                                void* context,
                                const z_bmqt_SessionOptions* options);

/**
 * @brief Starts a session synchronously.
 * 
 * @param session_obj Pointer to the Session object to start.
 * @param timeoutMs Timeout duration for starting the session.
 * 
 * @return Returns 0 upon successful start.
 */
int z_bmqa_Session__start(z_bmqa_Session* session_obj, int64_t timeoutMs);

/**
 * @brief Starts a session asynchronously.
 * 
 * @param session_obj Pointer to the Session object to start.
 * @param timeoutMs Timeout duration for starting the session.
 * 
 * @return Returns 0 upon successful start.
 */
int z_bmqa_Session__startAsync(z_bmqa_Session* session_obj, int64_t timeoutMs);

/**
 * @brief Stops a session synchronously.
 * 
 * @param session_obj Pointer to the Session object to stop.
 * 
 * @return Returns 0 upon successful stop.
 */
int z_bmqa_Session__stop(z_bmqa_Session* session_obj);

/**
 * @brief Stops a session asynchronously.
 * 
 * @param session_obj Pointer to the Session object to stop.
 * 
 * @return Returns 0 upon successful stop.
 */
int z_bmqa_Session__stopAsync(z_bmqa_Session* session_obj);

/**
 * @brief Finalizes the stopping of a session.
 * 
 * @param session_obj Pointer to the Session object.
 * 
 * @return Returns 0 upon successful finalization.
 */
int z_bmqa_Session__finalizeStop(z_bmqa_Session* session_obj);

/**
 * @brief Loads a MessageEventBuilder into the Session.
 * 
 * @param session_obj Pointer to the Session object.
 * @param builder Pointer to the MessageEventBuilder object to load.
 * 
 * @return Returns 0 upon successful loading.
 */
int z_bmqa_Session__loadMessageEventBuilder(
    z_bmqa_Session*             session_obj,
    z_bmqa_MessageEventBuilder* builder);

/**
 * @brief Loads a ConfirmEventBuilder into the Session.
 * 
 * @param session_obj Pointer to the Session object.
 * @param builder Pointer to the ConfirmEventBuilder object to load.
 * 
 * @return Returns 0 upon successful loading.
 */
int z_bmqa_Session__loadConfirmEventBuilder(
    z_bmqa_Session*             session_obj,
    z_bmqa_ConfirmEventBuilder* builder);

/**
 * @brief Loads MessageProperties into the Session.
 * 
 * @param session_obj Pointer to the Session object.
 * @param buffer Pointer to store the loaded MessageProperties.
 * 
 * @return Returns 0 upon successful loading.
 */
int z_bmqa_Session__loadMessageProperties(z_bmqa_Session* session_obj,
                                          z_bmqa_MessageProperties** buffer);

/**
 * @brief Opens a queue synchronously.
 * 
 * @param session_obj Pointer to the Session object.
 * @param queueId Pointer to the QueueId object.
 * @param uri URI for the queue.
 * @param flags Flags for opening the queue.
 * @param status Pointer to store the OpenQueueStatus object.
 * 
 * @return Returns 0 upon successful opening.
 */
int z_bmqa_Session__openQueueSync(z_bmqa_Session*          session_obj,
                                  z_bmqa_QueueId*          queueId,
                                  const char*              uri,
                                  uint64_t                 flags,
                                  z_bmqa_OpenQueueStatus** status);

/**
 * @brief Configures a queue synchronously.
 * 
 * @param session_obj Pointer to the Session object.
 * @param queueId Pointer to the QueueId object.
 * @param options Pointer to the QueueOptions object.
 * @param timeoutMs Timeout duration for configuring the queue.
 * @param status
 *  * @param status Pointer to store the ConfigureQueueStatus object.
 * 
 * @return Returns 0 upon successful configuration.
 */
int z_bmqa_Session__configureQueueSync(z_bmqa_Session*            session_obj,
                                       z_bmqa_QueueId*            queueId,
                                       const z_bmqt_QueueOptions* options,
                                       int64_t                    timeoutMs,
                                       z_bmqa_ConfigureQueueStatus** status);

/**
 * @brief Closes a queue synchronously.
 * 
 * @param session_obj Pointer to the Session object.
 * @param queueId Pointer to the QueueId object.
 * @param timeoutMs Timeout duration for closing the queue.
 * @param status Pointer to store the CloseQueueStatus object.
 * 
 * @return Returns 0 upon successful closing.
 */
int z_bmqa_Session__closeQueueSync(z_bmqa_Session*           session_obj,
                                   z_bmqa_QueueId*           queueId,
                                   int64_t                   timeoutMs,
                                   z_bmqa_CloseQueueStatus** status);

/**
 * @brief Posts a message event to the session.
 * 
 * @param session_obj Pointer to the Session object.
 * @param event Pointer to the MessageEvent object to post.
 * 
 * @return Returns 0 upon successful posting.
 */
int z_bmqa_Session__post(z_bmqa_Session*            session_obj,
                         const z_bmqa_MessageEvent* event);

/**
 * @brief Confirms a message.
 * 
 * @param session_obj Pointer to the Session object.
 * @param message Pointer to the Message object to confirm.
 * 
 * @return Returns 0 upon successful confirmation.
 */
int z_bmqa_Session__confirmMessage(z_bmqa_Session*       session_obj,
                                   const z_bmqa_Message* message);

/**
 * @brief Confirms a message with a cookie.
 * 
 * @param session_obj Pointer to the Session object.
 * @param cookie Pointer to the MessageConfirmationCookie object.
 * 
 * @return Returns 0 upon successful confirmation.
 */
int z_bmqa_Session__confirmMessageWithCookie(
    z_bmqa_Session*                         session_obj,
    const z_bmqa_MessageConfirmationCookie* cookie);

/**
 * @brief Confirms multiple messages using a ConfirmEventBuilder.
 * 
 * @param session_obj Pointer to the Session object.
 * @param builder Pointer to the ConfirmEventBuilder object containing the messages to confirm.
 * 
 * @return Returns 0 upon successful confirmation.
 */
int z_bmqa_Session__confirmMessages(z_bmqa_Session*             session_obj,
                                    z_bmqa_ConfirmEventBuilder* builder);

#if defined(__cplusplus)
}
#endif

#endif

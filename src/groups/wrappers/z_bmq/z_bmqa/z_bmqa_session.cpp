#include <bmqa_openqueuestatus.h>
#include <bmqa_session.h>
#include <bmqt_sessionoptions.h>
#include <bslma_managedptr.h>
#include <z_bmqa_closequeuestatus.h>
#include <z_bmqa_openqueuestatus.h>
#include <z_bmqa_session.h>
#include <z_bmqt_sessionoptions.h>

class CustomEventHandler : public BloombergLP::bmqa::SessionEventHandler {
  private:
    z_bmqa_SessionEventHandlers d_eventHandlers;
    void*                       d_context;

  public:
    CustomEventHandler(z_bmqa_SessionEventHandlers eventHandlers,
                       void*                       context)
    : d_eventHandlers(eventHandlers)
    , d_context(context)
    {
    }

    void onMessageEvent(const BloombergLP::bmqa::MessageEvent& messageEvent) {
        const z_bmqa_MessageEvent* messageEvent_p = reinterpret_cast<const z_bmqa_MessageEvent*>(&messageEvent);
        d_eventHandlers.onMessageEvent(messageEvent_p, d_context);
    }

    void onSessionEvent(const BloombergLP::bmqa::SessionEvent& sessionEvent) {
        const z_bmqa_SessionEvent* sessionEvent_p = reinterpret_cast<const z_bmqa_SessionEvent*>(&sessionEvent);
        d_eventHandlers.onSessionEvent(sessionEvent_p, d_context);
    }
};

int z_bmqa_Session__delete(z_bmqa_Session** session_obj)
{
    using namespace BloombergLP;

    BSLS_ASSERT(session_obj != NULL);

    bmqa::Session* session_p = reinterpret_cast<bmqa::Session*>(*session_obj);
    delete session_p;
    *session_obj = NULL;

    return 0;
}

int z_bmqa_Session__create(z_bmqa_Session**             session_obj,
                           const z_bmqt_SessionOptions* options)
{
    using namespace BloombergLP;

    bmqa::Session* session_p;
    if (options) {
        const bmqt::SessionOptions* options_p =
            reinterpret_cast<const bmqt::SessionOptions*>(options);
        session_p = new bmqa::Session(*options_p);
    }
    else {
        session_p = new bmqa::Session();
    }
    *session_obj = reinterpret_cast<z_bmqa_Session*>(session_p);
    return 0;
}

int z_bmqa_Session__createAsync(z_bmqa_Session**             session_obj,
                                z_bmqa_SessionEventHandlers eventHandlers,
                                void* context,
                                const z_bmqt_SessionOptions* options)
{
    using namespace BloombergLP;

    bmqa::Session*             session_p;
    bslma::ManagedPtr<bmqa::SessionEventHandler> eventHandler_mp(new CustomEventHandler(eventHandlers, context));
    if (options) {
        const bmqt::SessionOptions* options_p =
            reinterpret_cast<const bmqt::SessionOptions*>(options);
        session_p = new bmqa::Session(
            eventHandler_mp,
            *options_p);
    }
    else {
        session_p = new bmqa::Session(
            eventHandler_mp);
    }
    *session_obj = reinterpret_cast<z_bmqa_Session*>(session_p);
    return 0;
}

int z_bmqa_Session__start(z_bmqa_Session* session_obj, int64_t timeoutMs)
{
    using namespace BloombergLP;

    bmqa::Session* session_p = reinterpret_cast<bmqa::Session*>(session_obj);
    if (timeoutMs != 0) {
        bsls::TimeInterval timeout;
        timeout.addMilliseconds(timeoutMs);
        return session_p->start(timeout);
    }
    else {
        return session_p->start();
    }
}

int z_bmqa_Session__startAsync(z_bmqa_Session* session_obj, int64_t timeoutMs)
{
    using namespace BloombergLP;

    bmqa::Session* session_p = reinterpret_cast<bmqa::Session*>(session_obj);
    if (timeoutMs != 0) {
        bsls::TimeInterval timeout;
        timeout.addMilliseconds(timeoutMs);
        return session_p->startAsync(timeout);
    }
    else {
        return session_p->startAsync();
    }
}

int z_bmqa_Session__stop(z_bmqa_Session* session_obj)
{
    using namespace BloombergLP;

    bmqa::Session* session_p = reinterpret_cast<bmqa::Session*>(session_obj);
    session_p->stop();

    return 0;
}

int z_bmqa_Session__stopAsync(z_bmqa_Session* session_obj)
{
    using namespace BloombergLP;

    bmqa::Session* session_p = reinterpret_cast<bmqa::Session*>(session_obj);
    session_p->stopAsync();

    return 0;
}

int z_bmqa_Session__finalizeStop(z_bmqa_Session* session_obj)
{
    using namespace BloombergLP;

    bmqa::Session* session_p = reinterpret_cast<bmqa::Session*>(session_obj);
    session_p->finalizeStop();
    return 0;
}

int z_bmqa_Session__loadMessageEventBuilder(
    z_bmqa_Session*             session_obj,
    z_bmqa_MessageEventBuilder* builder)
{
    using namespace BloombergLP;

    bmqa::Session* session_p = reinterpret_cast<bmqa::Session*>(session_obj);
    bmqa::MessageEventBuilder* builder_p =
        reinterpret_cast<bmqa::MessageEventBuilder*>(builder);

    session_p->loadMessageEventBuilder(builder_p);
    return 0;
}

int z_bmqa_Session__loadConfirmEventBuilder(
    z_bmqa_Session*             session_obj,
    z_bmqa_ConfirmEventBuilder* builder)
{
    using namespace BloombergLP;

    bmqa::Session* session_p = reinterpret_cast<bmqa::Session*>(session_obj);
    bmqa::ConfirmEventBuilder* builder_p =
        reinterpret_cast<bmqa::ConfirmEventBuilder*>(builder);

    session_p->loadConfirmEventBuilder(builder_p);
    return 0;
}

int z_bmqa_Session__loadMessageProperties(z_bmqa_Session* session_obj,
                                          z_bmqa_MessageProperties** buffer)
{
    using namespace BloombergLP;

    bmqa::Session* session_p = reinterpret_cast<bmqa::Session*>(session_obj);
    bmqa::MessageProperties* buffer_p =
        reinterpret_cast<bmqa::MessageProperties*>(buffer);

    session_p->loadMessageProperties(buffer_p);
    return 0;
}

// int z_bmqa_Session__getQueueIdWithUri(z_bmqa_Session* session_obj,
// z_bmqa_QueueId** queueId, const z_bmqt_Uri* uri){
//     using namespace BloombergLP;

//     bmqa::Session* session_p =
//     reinterpret_cast<bmqa::Session*>(session_obj); bmqa::Q* buffer_p =
//     reinterpret_cast<bmqa::MessageProperties*>(uri);

//     session_p->getQueueId(buffer_p);
//     return 0;
// }

int z_bmqa_Session__openQueueSync(z_bmqa_Session*          session_obj,
                                  z_bmqa_QueueId*          queueId,
                                  const char*              uri,
                                  uint64_t                 flags,
                                  z_bmqa_OpenQueueStatus** status)
{
    using namespace BloombergLP;

    bmqa::Session* session_p = reinterpret_cast<bmqa::Session*>(session_obj);
    bmqa::QueueId* queueId_p = reinterpret_cast<bmqa::QueueId*>(queueId);
    bmqa::OpenQueueStatus* status_p = new bmqa::OpenQueueStatus();

    *status_p = session_p->openQueueSync(queueId_p, uri, flags);
    *status   = reinterpret_cast<z_bmqa_OpenQueueStatus*>(status_p);
    return 0;
}

int z_bmqa_Session__configureQueueSync(z_bmqa_Session*            session_obj,
                                       z_bmqa_QueueId*            queueId,
                                       const z_bmqt_QueueOptions* options,
                                       int64_t                    timeoutMs,
                                       z_bmqa_ConfigureQueueStatus** status)
{
    using namespace BloombergLP;

    bmqa::Session* session_p = reinterpret_cast<bmqa::Session*>(session_obj);
    bmqa::QueueId* queueId_p = reinterpret_cast<bmqa::QueueId*>(queueId);
    bmqa::ConfigureQueueStatus* status_p = new bmqa::ConfigureQueueStatus();
    const bmqt::QueueOptions*   options_p =
        reinterpret_cast<const bmqt::QueueOptions*>(options);

    // Implement timeout

    *status_p = session_p->configureQueueSync(queueId_p, *options_p);
    *status   = reinterpret_cast<z_bmqa_ConfigureQueueStatus*>(status_p);
    return 0;
}

int z_bmqa_Session__closeQueueSync(z_bmqa_Session*           session_obj,
                                   z_bmqa_QueueId*           queueId,
                                   int64_t                   timeoutMs,
                                   z_bmqa_CloseQueueStatus** status)
{
    using namespace BloombergLP;

    bmqa::Session* session_p = reinterpret_cast<bmqa::Session*>(session_obj);
    bmqa::QueueId* queueId_p = reinterpret_cast<bmqa::QueueId*>(queueId);
    bmqa::CloseQueueStatus* status_p = new bmqa::CloseQueueStatus();

    // Implement timeout

    *status_p = session_p->closeQueueSync(queueId_p);
    *status   = reinterpret_cast<z_bmqa_CloseQueueStatus*>(status_p);
    return 0;
}

int z_bmqa_Session__post(z_bmqa_Session*            session_obj,
                         const z_bmqa_MessageEvent* event)
{
    using namespace BloombergLP;

    bmqa::Session* session_p = reinterpret_cast<bmqa::Session*>(session_obj);
    const bmqa::MessageEvent* event_p =
        reinterpret_cast<const bmqa::MessageEvent*>(event);

    session_p->post(*event_p);
    return 0;
}

// int z_bmqa_Session__confirmMessage(z_bmqa_Session*       session_obj,
//                                    const z_bmqa_Message* message)
// {
//     using namespace BloombergLP;
//     bmqa::Session* session_p =
//     reinterpret_cast<bmqa::Session*>(session_obj);
// }

// int z_bmqa_Session__confirmMessageWithCookie(
//     z_bmqa_Session*                         session_obj,
//     const z_bmqa_MessageConfirmationCookie* cookie)
// {
//     using namespace BloombergLP;
//     bmqa::Session* session_p =
//     reinterpret_cast<bmqa::Session*>(session_obj);
// }

int z_bmqa_Session__confirmMessages(z_bmqa_Session*             session_obj,
                                    z_bmqa_ConfirmEventBuilder* builder)
{
    using namespace BloombergLP;
    bmqa::Session* session_p = reinterpret_cast<bmqa::Session*>(session_obj);
    bmqa::ConfirmEventBuilder* builder_p =
        reinterpret_cast<bmqa::ConfirmEventBuilder*>(builder);
    return session_p->confirmMessages(builder_p);
}
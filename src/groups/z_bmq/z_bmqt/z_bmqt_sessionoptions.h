#ifndef INCLUDED_Z_BMQT_SESSIONOPTIONS
#define INCLUDED_Z_BMQT_SESSIONOPTIONS

#if defined(__cplusplus)
extern "C" {
#endif


typedef struct z_bmqt_SessionOptions z_bmqt_SessionOptions;

int z_bmqt_SessionOptions__create(z_bmqt_SessionOptions** options);

const char* z_bmqt_SessionOptions__brokerUri(const z_bmqt_SessionOptions* options);


#if defined(__cplusplus)
}
#endif

#endif
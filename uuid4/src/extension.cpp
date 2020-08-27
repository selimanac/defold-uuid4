// uuid4.cpp
// Extension lib defines
#define LIB_NAME "uuid4"
#define MODULE_NAME "uuid4"

// include the Defold SDK
#include <dmsdk/sdk.h>
#include <uuid4.h>

UUID4_STATE_T state;
UUID4_T uuid;

static int generate(lua_State *L)
{
    uuid4_gen(&state, &uuid);
    char buffer[UUID4_STR_BUFFER_SIZE];
    if (!uuid4_to_s(uuid, buffer, sizeof(buffer)))
    {
        dmLogError("uuid4 error!");
        return 0;
    }

    lua_pushstring(L, buffer);
    return 1;
}

// Functions exposed to Lua
static const luaL_reg Module_methods[] =
    {
        {"generate", generate},
        {0, 0}};

static void LuaInit(lua_State *L)
{
    int top = lua_gettop(L);

    // Register lua names
    luaL_register(L, MODULE_NAME, Module_methods);

    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

dmExtension::Result AppInitializeuuid4(dmExtension::AppParams *params)
{
    dmLogInfo("AppInitializeuuid4\n");
    return dmExtension::RESULT_OK;
}

dmExtension::Result Initializeuuid4(dmExtension::Params *params)
{
    // Init Lua
    LuaInit(params->m_L);
    dmLogInfo("Registered %s Extension\n", MODULE_NAME);
    dmLogInfo("%s Extension Seeded\n", MODULE_NAME);
    uuid4_seed(&state);
    return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(uuid4, LIB_NAME, AppInitializeuuid4, 0, Initializeuuid4, 0, 0, 0)

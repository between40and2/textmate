#include <scope/scope.h>

void test_scope_append ()
{
	scope::scope_t scope("foo bar");
	OAK_ASSERT_EQ("bar", scope.back());
	scope = scope.append("some invalid..scope");
	OAK_ASSERT_EQ("some invalid..scope", scope.back());
	scope = scope.parent();
	OAK_ASSERT_EQ("foo bar", to_s(scope));
	scope = scope.parent();
	OAK_ASSERT_EQ("foo", to_s(scope));
}
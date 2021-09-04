#if !defined LONGLONG_INC
#define LONGLONG_INC

#define LONGLONG_MAX_LEN 	20
#define LONG_LONG_MAX_LEN 	20
#define MAX_LONGLONG_LEN 	20
#define MAX_LONG_LONG_LEN	20

enum stlonglong
{
	lllow,
	llhigh,
};

native llSetValueString(value[], const stringValue[]);
native llGetValueString(value[], const dest[]);

stock llcmp(value[], val)
{
	static Vhigh, Vlow;
	Vhigh = value[llhigh];
	Vlow = value[lllow];

	if (Vhigh != 0)
	{
		if (Vhigh > 0) return 1;
		return -1;
	}
	if (Vlow >= val) return (val < Vlow);
	return -1;
}

stock llcmp64(value[], valuelow, valuehigh)
{
	static Vhigh, Vlow;
	Vhigh = value[llhigh];
	Vlow = value[lllow];

	if (Vhigh != valuehigh)
	{
		if (Vhigh >= valuehigh) return (valuehigh < Vhigh);
		return -1;
	}
	if (Vlow >= valuelow) return (valuelow < Vlow);
	return -1;
}

native llcmpString(value[], const stringValue[]);

native lladd(value[], val);
native lladd64(value[], valuelow, valuehigh);
native lladdString(value[], const stringValue[]);

native llsub(value[], val);
native llsub64(value[], valuelow, valuehigh);
native llsubString(value[], const stringValue[]);


#define llcmp(%0,%2,%1)					(llcmp(%0, %1) %2 0)
#define llcmp64(%0,%3,%1,%2) 			(llcmp64(%0, %1, %2) %3 0)
#define llcmpString(%0,%2,%1) 		(llcmpString(%0, %1) %2 0)

#endif
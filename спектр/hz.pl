


open f, "konkurs7.txt" or die $!; binmode f;
read f, $_, -s f;
close f;

@A = split /   2012 	\d+	/;

print @A;
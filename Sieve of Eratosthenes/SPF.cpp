void sieve ( ){ /// O( NloglogN ).

    for ( ll i = 2 ; i<N ; ++i ) lpf[i] = i;

    for ( ll i = 2 ; i<N ; ++i ){
         if ( lpf[i] == i ){
             for ( ll j = i + i ; j < N ; j+=i ) lpf[j] = min ( i , lpf[j] );
         }
    }
}

class apache {
        package {'apache2-mpm-prefork':
                   ensure => installed,
        }
        service { 'apache2':
                   ensure => running,
                   hasstatus => true,
                   hasrestart => true,
	}
}
   

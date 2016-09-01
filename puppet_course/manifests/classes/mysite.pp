class mysite {
        include apache
        file { '/etc/apache2/sites-enabled/mysite':
                owner => root, group => root, mode => 0644,
                source => "puppet:///files/mysite/mysite_apache.conf",
                notify => Service['apache2'],
        }
        file { '/home/www/mysite.example.org':
                ensure => directory,
        }
        file { '/home/www/':
                ensure => directory,
        }
}

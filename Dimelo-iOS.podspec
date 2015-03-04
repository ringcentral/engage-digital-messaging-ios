Pod::Spec.new do |s|
  s.name     = 'Dimelo-iOS'
  s.version  = '1.2.1'
  s.license  = { :type => 'Proprietary', :file => 'LICENSE' }
  s.summary  = 'Dimelo Mobile Messaging SDK for iOS'
  s.homepage = 'https://github.com/dimelo/Dimelo-iOS'
  s.author   = { 'Dimelo' => 'support@dimelo.com' }
  s.source   = { :git => 'https://github.com/dimelo/Dimelo-iOS.git', :tag => 'v1.2.1' }

  s.source_files        = "Dimelo/*.h"
  s.public_header_files = "Dimelo/*.h"
  s.vendored_libraries  = "Dimelo/libDimelo-iOS.a"
  s.preserve_path       = "Dimelo/libDimelo-iOS.a"
  s.resources           = ["Dimelo/*.bundle", "Dimelo/*.xib"]
  s.platform            = :ios, '7.1'
  s.requires_arc        = true
  s.frameworks          = 'UIKit', 'Accelerate', 'MobileCoreServices', 'SystemConfiguration'
end

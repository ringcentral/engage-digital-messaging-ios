Pod::Spec.new do |s|
  s.name     = 'Dimelo-iOS'
  s.version  = '1.9.1'
  s.license  = { :type => 'Proprietary', :file => 'LICENSE' }
  s.summary  = 'Dimelo Mobile Messaging SDK for iOS'
  s.homepage = 'https://github.com/dimelo/Dimelo-iOS'
  s.author   = { 'Dimelo' => 'support@dimelo.com' }
  s.source   = { :git => 'https://github.com/dimelo/Dimelo-iOS.git', :tag => 'v1.9.1' }

  s.resources           = ["Dimelo/*.bundle", "Dimelo/*.xib"]
  s.platform            = :ios, '7.1'
  s.requires_arc        = true
  s.frameworks          = 'UIKit', 'Accelerate', 'MobileCoreServices', 'SystemConfiguration'
  s.vendored_frameworks = 'Dimelo.framework'

end

Pod::Spec.new do |s|
  s.name     = 'Dimelo-iOS'
  s.version  = '2.6.3'
  s.license  = { :type => 'Proprietary', :file => 'LICENSE' }
  s.summary  = 'Dimelo Mobile Messaging SDK for iOS'
  s.homepage = 'https://github.com/ringcentral/engage-digital-messaging-ios'
  s.author   = { 'Dimelo' => 'support@dimelo.com' }
  s.source   = { :git => 'https://github.com/ringcentral/engage-digital-messaging-ios.git', :tag => 'v2.6.3' }

  s.resources           = ["Dimelo/*.bundle", "Dimelo/*.xib"]
  s.platform            = :ios, '7.1'
  s.requires_arc        = true
  s.frameworks          = 'UIKit', 'Accelerate', 'MobileCoreServices', 'SystemConfiguration'
  s.vendored_frameworks = 'Dimelo.xcframework'

end
